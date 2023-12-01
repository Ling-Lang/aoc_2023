#!/bin/bash
set -euo pipefail
# SCRIPT_DIR=$(realpath "$(dirname "$0")")

if [[ $# != 1 ]]; then
  echo "Please provide a day number."
  echo "usage: $0 DAY"
  exit 1
fi

if [[ ! "$1" =~ ^(0[1-9]|1[0-9]|2[0-5])$ ]]; then
  echo "Argument '$1' is not a valid day."
  exit 1
fi

if [[ -z "${AOC_SESSION-"53616c7465645f5f50447bffb4afcea1c932eea906cfe7f049beb022c54b1daf3858892b39ae212312e3d21451209e6f7425444fec0e1caf3dd4cce0ad3e1bad"}" ]]; then
  echo "No session token set in \$AOC_SESSION."
  exit 1
fi

URL="https://adventofcode.com/2023/day/$(("10#$1" + 0))/input"
curl "$URL" --cookie "session=53616c7465645f5f50447bffb4afcea1c932eea906cfe7f049beb022c54b1daf3858892b39ae212312e3d21451209e6f7425444fec0e1caf3dd4cce0ad3e1bad" > input.in