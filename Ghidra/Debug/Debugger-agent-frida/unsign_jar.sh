#!/usr/bin/env bash
set -e
echo "Removing signature files from ${1}"
zip ${1} -d $(unzip -l Debugger-agent-frida-nodep.jar| grep '.SF$' | awk '{ print $4}')
