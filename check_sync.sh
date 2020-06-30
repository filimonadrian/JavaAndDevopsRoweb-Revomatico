#!/bin/bash

find . -name .git -type d | git remote update && git status -uno
