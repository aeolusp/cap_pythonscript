package main

// Simple webserver that responds to http request on port 80
// Based on web server code in https://golang.org/doc/article/wiki
// reference code from - https://github.com/ContainerSolutions/capabilities-blog/blob/master/server.go
/*
 * Compile
 *  go build server.go
 *
 * Run
 *  ./server
 *
 * Note:
 *  since server binds to port 80, it must be either run as root or with CAP_NET_BIND_SERVICE capabilities.
 */

import (
	"fmt"
	"log"
	"net/http"
)

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Successfully serving on port 80\n")
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":80", nil))
}
