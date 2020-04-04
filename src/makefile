BUILDDIR=build

build: build_server build_ambient
	cp readme $(BUILDDIR)/

.PHONY: build_server
build_server:
	go build -o $(BUILDDIR)/server server.go

.PHONY: build_ambient
build_ambient:
	gcc -o $(BUILDDIR)/set_ambient set_ambient.c -lcap-ng

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
