# DR

The code represents a server and client model, where the server is a virtual power plant, the client being a bucket and a bakery. The server dispatches power to the client based on its type, the server dispatches a random amount of power to a bucket until it is full, whereas it dispatches power at a constant rate for a battery. To run the code for either case,

First run the server code, on one terminal by creating an executable using the following command,

a)gcc -o batteryserver batteryserver.c 

b)./batteryserver

Now in another terminal create the executable for the client and run it,

c)gcc -o batteryclient batteryclient.c 

d)./batteryclient

Now repeat the same commands for the bucket by replacing the word "battery", by "bucket", in both server and client commands.

I have currently combined the server for all cases and i am implementing a weighted fair queuing model where packets from different clients are serviced based on a priority based model
