#!/bin/sh -e

while ! make; do
    printf "Retrying...\n"
done
