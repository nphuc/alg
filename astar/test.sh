#!/bin/bash

#astar shortest path
echo "--- astar run ----"
python astar.py< test.inp

echo "---bfs run ----"
python bfs.py<test.inp
