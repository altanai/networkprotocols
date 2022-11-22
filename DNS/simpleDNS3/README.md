# 

Libboost 

Boost is a set of libraries for the C++ programming language that provides support for tasks and structures such as linear algebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing.

libudns

UDNS is a stub DNS resolver library with ability to perform both syncronous and asyncronous DNS queries.

	apt install build-essential cmake libboost-all-dev libudns-dev


## RUn 


	 cmake .
	-- The C compiler identification is GNU 7.5.0
	-- The CXX compiler identification is GNU 7.5.0
	-- Check for working C compiler: /usr/bin/cc
	-- Check for working C compiler: /usr/bin/cc -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Detecting C compile features
	-- Detecting C compile features - done
	-- Check for working CXX compiler: /usr/bin/c++
	-- Check for working CXX compiler: /usr/bin/c++ -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Detecting CXX compile features
	-- Detecting CXX compile features - done
	-- Configuring done
	CMake Error at CMakeLists.txt:7 (add_executable):
	  Cannot find source file:

	    Test.cpp

	  Tried extensions .c .C .c++ .cc .cpp .cxx .m .M .mm .h .hh .h++ .hm .hpp
	  .hxx .in .txx


	-- Generating done
	-- Build files have been written to: /home/osboxes/networkprotocols/DNS/simpleDNS3


make


	Scanning dependencies of target cpp-dns
	[ 33%] Building CXX object CMakeFiles/cpp-dns.dir/DNSResolver.cpp.o
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp: In member function ‘void DNSWkSpace::DNSResolver::__init()’:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: error: ‘system_category’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	   _GLIBCXX_CONST const error_category& system_category() noexcept;
	                                        ^~~~~~~~~~~~~~~
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	In file included from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:24:0,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/asio/error.hpp:259:3: note:   ‘boost::asio::error::system_category’
	   system_category BOOST_ASIO_UNUSED_VARIABLE
	   ^~~~~~~~~~~~~~~
	In file included from /usr/include/boost/asio/io_service.hpp:25:0,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/error_code.hpp:196:47: note:   ‘boost::system::system_category’
	     BOOST_SYSTEM_DECL const error_category &  system_category() BOOST_SYSTEM_NOEXCEPT;
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: error: ‘system_error’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:341:9: note:   ‘std::system_error’
	   class system_error : public std::runtime_error
	         ^~~~~~~~~~~~
	In file included from /usr/include/boost/asio/detail/impl/throw_error.ipp:21:0,
	                 from /usr/include/boost/asio/detail/throw_error.hpp:52,
	                 from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:23,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/system_error.hpp:22:32: note:   ‘boost::system::system_error’
	     class BOOST_SYMBOL_VISIBLE system_error : public std::runtime_error
	                                ^~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp: In member function ‘void DNSWkSpace::DNSResolver::__open()’:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: error: ‘system_category’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	   _GLIBCXX_CONST const error_category& system_category() noexcept;
	                                        ^~~~~~~~~~~~~~~
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	In file included from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:24:0,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/asio/error.hpp:259:3: note:   ‘boost::asio::error::system_category’
	   system_category BOOST_ASIO_UNUSED_VARIABLE
	   ^~~~~~~~~~~~~~~
	In file included from /usr/include/boost/asio/io_service.hpp:25:0,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/error_code.hpp:196:47: note:   ‘boost::system::system_category’
	     BOOST_SYSTEM_DECL const error_category &  system_category() BOOST_SYSTEM_NOEXCEPT;
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: error: ‘system_error’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:341:9: note:   ‘std::system_error’
	   class system_error : public std::runtime_error
	         ^~~~~~~~~~~~
	In file included from /usr/include/boost/asio/detail/impl/throw_error.ipp:21:0,
	                 from /usr/include/boost/asio/detail/throw_error.hpp:52,
	                 from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:23,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/system_error.hpp:22:32: note:   ‘boost::system::system_error’
	     class BOOST_SYMBOL_VISIBLE system_error : public std::runtime_error
	                                ^~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp: In member function ‘void DNSWkSpace::DNSResolver::set_servers(const std::initializer_list<std::__cxx11::basic_string<char> >&)’:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: error: ‘system_category’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:47: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	   _GLIBCXX_CONST const error_category& system_category() noexcept;
	                                        ^~~~~~~~~~~~~~~
	/usr/include/c++/7/system_error:134:40: note:   ‘std::_V2::system_category’
	In file included from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:24:0,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/asio/error.hpp:259:3: note:   ‘boost::asio::error::system_category’
	   system_category BOOST_ASIO_UNUSED_VARIABLE
	   ^~~~~~~~~~~~~~~
	In file included from /usr/include/boost/asio/io_service.hpp:25:0,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/error_code.hpp:196:47: note:   ‘boost::system::system_category’
	     BOOST_SYSTEM_DECL const error_category &  system_category() BOOST_SYSTEM_NOEXCEPT;
	                                               ^~~~~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:0:
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: error: ‘system_error’ was not declared in this scope
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: suggested alternatives:
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^
	/home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:21:27: note: in definition of macro ‘THROW_ERRNO’
	 #define THROW_ERRNO throw system_error(errno, system_category(), strerror(errno))
	                           ^~~~~~~~~~~~
	In file included from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:4:0,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/c++/7/system_error:341:9: note:   ‘std::system_error’
	   class system_error : public std::runtime_error
	         ^~~~~~~~~~~~
	In file included from /usr/include/boost/asio/detail/impl/throw_error.ipp:21:0,
	                 from /usr/include/boost/asio/detail/throw_error.hpp:52,
	                 from /usr/include/boost/asio/detail/impl/posix_mutex.ipp:23,
	                 from /usr/include/boost/asio/detail/posix_mutex.hpp:73,
	                 from /usr/include/boost/asio/detail/mutex.hpp:25,
	                 from /usr/include/boost/asio/detail/service_registry.hpp:20,
	                 from /usr/include/boost/asio/impl/io_service.hpp:19,
	                 from /usr/include/boost/asio/io_service.hpp:767,
	                 from /usr/include/boost/asio/basic_io_object.hpp:19,
	                 from /usr/include/boost/asio/basic_socket.hpp:20,
	                 from /usr/include/boost/asio/basic_datagram_socket.hpp:20,
	                 from /usr/include/boost/asio.hpp:21,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.hpp:18,
	                 from /home/osboxes/networkprotocols/DNS/simpleDNS3/DNSResolver.cpp:2:
	/usr/include/boost/system/system_error.hpp:22:32: note:   ‘boost::system::system_error’
	     class BOOST_SYMBOL_VISIBLE system_error : public std::runtime_error
	                                ^~~~~~~~~~~~
	CMakeFiles/cpp-dns.dir/build.make:62: recipe for target 'CMakeFiles/cpp-dns.dir/DNSResolver.cpp.o' failed
	make[2]: *** [CMakeFiles/cpp-dns.dir/DNSResolver.cpp.o] Error 1
	CMakeFiles/Makefile2:67: recipe for target 'CMakeFiles/cpp-dns.dir/all' failed
	make[1]: *** [CMakeFiles/cpp-dns.dir/all] Error 2
	Makefile:83: recipe for target 'all' failed
	make: *** [all] Error 2


## 

Ref :

	-https://www.corpit.ru/mjt/udns.html