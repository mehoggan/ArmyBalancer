#
# Regular cron jobs for the armybalancer package
#
0 4	* * *	root	[ -x /usr/bin/armybalancer_maintenance ] && /usr/bin/armybalancer_maintenance
