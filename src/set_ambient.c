/*
 * Simple program to start the given process with CAP_NET_BIND_SERVICE in the
 * ambient capabilities. 
 *
 * Based on test program by Christoph Lameter.
 *
 * (C) 2015 Christoph Lameter <cl@linux.com>
 * (C) 2019 Adrian Mouat <adrian.mouat@container-solutions.com>
 *
 * Released under: GPL v3 or later.
 * 
 * Refer readme for more details...
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <cap-ng.h>
#include <sys/prctl.h>
#include <linux/capability.h>

static void set_ambient_cap(int cap)
{
	int rc;

	capng_get_caps_process();
	rc = capng_update(CAPNG_ADD, CAPNG_INHERITABLE, cap);
	if (rc) {
		printf("Cannot add inheritable cap\n");
		exit(2);
	}
	capng_apply(CAPNG_SELECT_CAPS);

	/* Note the two 0s at the end. Kernel checks for these */
	if (prctl(PR_CAP_AMBIENT, PR_CAP_AMBIENT_RAISE, cap, 0, 0)) {
		perror("Cannot set cap");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	int rc;

	set_ambient_cap(CAP_NET_BIND_SERVICE);

	printf("Starting process with CAP_NET_BIND_SERVICE in ambient\n");
	if (execv(argv[1], argv + 1))
		perror("Cannot exec");

	return 0;
}
