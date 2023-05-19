# dnsclient
Implementation of a C client to query the Domain Name System for IP addresses. Program that takes a host and port like luddy.indiana.edu 80 and prints the IP addresses associated with that host and domain.

# How to use

program takes two arguments: a host such as www.example.com, and a port such as 80 and prints out every IPv4 and IPv6 address associated with that host.

Output should be a single line per address, with the first 4 characters being either IPv4 or IPv6 followed by a space ’ ‘, followed by the corresponding address.

# example

$ make

$ ./dnscmd www.example.com 80

# Result

IPv6 2606:2800:220:1:248:1893:25c8:1946

IPv4 93.184.216.34
