#include <stdio.h>
#include <stdlib.h>
#include <libnet.h>

// function returns a pointer to the libnet context, which you’ll need for all header building functions.
int main() {

  libnet_t *l;  /* the libnet context */
  char errbuf[LIBNET_ERRBUF_SIZE];

  l = libnet_init(LIBNET_RAW4, NULL, errbuf);
  if ( l == NULL ) {
    fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  libnet_destroy(l);
  return 0;
}