#!/bin/bash

dh_make -s -c gpl -e matthew.hoggan@matthewh.me --createorig -p armybalancer_1.0.0
dpkg-buildpackage
