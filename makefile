BUILDDIR=build
SRCDIR=src

build: build_server build_ambient
	cp $(SRCDIR)/readme $(BUILDDIR)/

.PHONY: build_server
build_server:
	go build -o $(BUILDDIR)/server $(SRCDIR)/server.go

.PHONY: build_ambient
build_ambient:
	gcc -o $(BUILDDIR)/set_ambient $(SRCDIR)/set_ambient.c -lcap-ng

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
