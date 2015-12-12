#!/bin/bash

while true; do
	filename=timelapse/$(date -u +"%Y%m%d_%H_%M_%S").jpg
	scrot $filename
	sleep 60
done
