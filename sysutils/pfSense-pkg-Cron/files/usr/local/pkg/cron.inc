<?php
/*
	cron.inc
	part of pfSense (https://www.pfSense.org/)
	Copyright (C) 2008 Mark J Crane
	Copyright (C) 2015 ESF, LLC
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright
	   notice, this list of conditions and the following disclaimer in the
	   documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
	AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
	OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
require_once("pfsense-utils.inc");
require_once("services.inc");
require_once("util.inc");

function cron_sync_package() {
	configure_cron();
	// Previous package versions were "helpfully" killing cron on uninstall.
	// Also, need to make sure cron is running, otherwise the package is useless.
	// configure_cron() function in services.inc already does this check on pfSense >=2.2.5
	$pfs_version = str_replace(".", "", substr(trim(file_get_contents("/etc/version")), 0, 5));
	if ($pfs_version < 225) {
		if (!is_process_running("cron")) {
			exec("cd /tmp && /usr/sbin/cron -s 2>/dev/null");
		}
	}
}

function cron_install_command() {
	// Clean up possible lingering garbage after previous package versions
	unlink_if_exists("/usr/local/etc/rc.d/cron.sh");
}

function cron_deinstall_command() {
	rmdir_recursive("/usr/local/www/packages/cron");
}

?>