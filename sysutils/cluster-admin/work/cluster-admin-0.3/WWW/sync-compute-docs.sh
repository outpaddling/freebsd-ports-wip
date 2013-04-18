#!/bin/sh

rsync -av --delete compute-01:/usr/local/share/doc/ Compute-node-docs
chmod -R a+rX Compute-node-docs

