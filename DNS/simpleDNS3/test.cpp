#include "dns.hpp"

#include <mutex>
#include <iostream>

using DNSResolver = DNSWkSpace::DNSResolver;

int main(int argc, char **argv) {
	boost::asio::io_service iosvc;
	std::mutex print_lock;
	DNSResolver d(iosvc, {"1.1.1.1", "8.8.8.8", "8.8.4.4"});

	d.resolve_a6("google.com", [&](int err, auto& addrs, auto& qname, auto& cname, uint ttl){
		if (!err) {
			std::unique_lock l(print_lock);

			std::cout << "==================" << "\n";
			std::cout << "Query: " << qname << "\n";
			std::cout << "CNAME: " << cname << "\n";
			std::cout << "TTL: " << ttl << "\n";

			for (auto &it : addrs) {
				std::cout << "AAAA Record: " << it.to_string() << "\n";
			}
			std::cout << "==================" << "\n";
		}
	});

	// d.resolve_a4("baidu.com", [&](int err, auto& addrs, auto& qname, auto& cname, uint ttl){
	// 	if (!err) {
	// 		std::unique_lock l(print_lock);

	// 		std::cout << "==================" << "\n";
	// 		std::cout << "Query: " << qname << "\n";
	// 		std::cout << "CNAME: " << cname << "\n";
	// 		std::cout << "TTL: " << ttl << "\n";

	// 		for (auto &it : addrs) {
	// 			std::cout << "A Record: " << it.to_string() << "\n";
	// 		}
	// 		std::cout << "==================" << "\n";
	// 	}
	// });

	// d.resolve_a4ptr(boost::asio::ip::address_v4::from_string("1.1.1.1"),
	// 		[&](int err, auto& hosts, auto& qname, auto& cname, uint ttl){
	// 			if (!err) {
	// 				std::unique_lock l(print_lock);

	// 				std::cout << "==================" << "\n";
	// 				std::cout << "Query: " << qname << "\n";
	// 				std::cout << "CNAME: " << cname << "\n";
	// 				std::cout << "TTL: " << ttl << "\n";

	// 				for (auto &it : hosts) {
	// 					std::cout << "PTR Record: " << it << "\n";
	// 				}

	// 				std::cout << "==================" << "\n";
	// 			}
	// 		});

	// d.resolve_a6ptr(boost::asio::ip::address_v6::from_string("2404:6800:4004:81f::200e"),
	// 		[&](int err, auto& hosts, auto& qname, auto& cname, uint ttl){
	// 			if (!err) {
	// 				std::unique_lock l(print_lock);

	// 				std::cout << "==================" << "\n";
	// 				std::cout << "Query: " << qname << "\n";
	// 				std::cout << "CNAME: " << cname << "\n";
	// 				std::cout << "TTL: " << ttl << "\n";

	// 				for (auto &it : hosts) {
	// 					std::cout << "PTR Record: " << it << "\n";
	// 				}

	// 				std::cout << "==================" << "\n";
	// 			}
	// 		});

	// d.resolve_mx("google.com", [&](int err, auto& hosts, auto& qname, auto& cname, uint ttl){
	// 	if (!err) {
	// 		std::unique_lock l(print_lock);

	// 		std::cout << "==================" << "\n";
	// 		std::cout << "Query: " << qname << "\n";
	// 		std::cout << "CNAME: " << cname << "\n";
	// 		std::cout << "TTL: " << ttl << "\n";

	// 		for (auto &it : hosts) {
	// 			std::cout << "MX Record: " << it.priority << " " << it.name << "\n";
	// 		}

	// 		std::cout << "==================" << "\n";
	// 	}
	// });

	// d.resolve_srv("riot.im", "matrix", "tcp", [&](int err, auto& hosts, auto& qname, auto& cname, uint ttl){
	// 	if (!err) {
	// 		std::unique_lock l(print_lock);

	// 		std::cout << "==================" << "\n";
	// 		std::cout << "Query: " << qname << "\n";
	// 		std::cout << "CNAME: " << cname << "\n";
	// 		std::cout << "TTL: " << ttl << "\n";

	// 		for (auto &it : hosts) {
	// 			std::cout << "SRV Record: " << it.priority << " " << it.weight << " " << it.port << " "  << it.name << "\n";
	// 		}

	// 		std::cout << "==================" << "\n";
	// 	}
	// });

	// d.resolve_txt("google.com", [&](int err, auto& hosts, auto& qname, auto& cname, uint ttl){
	// 	if (!err) {
	// 		std::unique_lock l(print_lock);

	// 		std::cout << "==================" << "\n";
	// 		std::cout << "Query: " << qname << "\n";
	// 		std::cout << "CNAME: " << cname << "\n";
	// 		std::cout << "TTL: " << ttl << "\n";

	// 		for (auto &it : hosts) {
	// 			std::cout << "TXT Record: " << it << "\n";
	// 		}

	// 		std::cout << "==================" << "\n";
	// 	}
	// });


	// d.resolve_a4("kefpdngjvoeqjgp3rnskldv", [&](int err, auto& addrs, auto& qname, auto& cname, uint ttl){
	// 	std::unique_lock l(print_lock);
	// 	std::cout << "==================" << "\n";
	// 	std::cout << "Oops. " << DNSResolver::error_string(err) << "\n";
	// 	std::cout << "==================" << "\n";

	// });

	iosvc.run();

}