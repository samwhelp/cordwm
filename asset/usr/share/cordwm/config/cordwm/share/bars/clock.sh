#!/usr/bin/env bash

interval=0

clock() {
	printf "^c#222526^ ^b#6080a0^ 󱑆 "
	printf "^c#222526^^b#6f8faf^ $(date '+%a, %Y-%m-%d %H:%M:%S') "
}

while true; do

	interval=$((interval + 1))

	sleep 1 && xsetroot -name "$(clock)"
done
