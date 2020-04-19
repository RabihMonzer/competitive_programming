<?php

// https://codeforces.com/problemset/problem/1331/D

$handle = fopen('php://stdin', 'r');
$hexadecimalNumber = fgets($handle);

echo hexdec($hexadecimalNumber) % 2;
