#!/bin/bash
git init
git add .
git commit -am "initial commit"
git branch beta
git branch
git checkout beta
git add .
git commit -am "change to beta"
git checkout master
