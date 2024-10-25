## Algorithm: Port Scanner

## Step 1: Define Objectives and Scanning Type

Objective: The goal is to scan a specific range of ports on a target IP or hostname to determine which ports are open, closed, or filtered.

Scanning Types: Decide on the type of scan you want to implement:

TCP SYN scan: Sends a SYN packet and waits for a response (more stealthy).
TCP Connect scan: Attempts to establish a full connection (three-way handshake).
UDP scan: Sends UDP packets to check for open ports (less reliable due to the lack of a connection handshake).
Ping scan: Uses ICMP to detect if a host is up before scanning.
For simplicity, this algorithm will focus on TCP connect scanning, which establishes a full connection to the target port to determine its status.

## Step 2: Gather Input from the User

Target Host/IP: Prompt the user to enter the target IP address or hostname.
Port Range: Ask the user for the range of ports to scan (e.g., 1-65535 for all ports, or a specific subset like 20-80).
Timeout Duration: Optionally, allow the user to specify a timeout duration for each port to wait for a response (e.g., 1-5 seconds).
Concurrency: Ask if the user wants to perform the scan in parallel (multithreaded) or sequentially.

## Step 3: Resolve Hostname to IP (if necessary)

If the user provided a hostname, perform a DNS lookup to resolve the hostname into an IP address.
If the input is already an IP address, skip this step and proceed.

## Step 4: Initialize Variables

Port List: Create a list of all the ports to scan (from the specified range).
Status Dictionary: Initialize a dictionary or data structure to store the status of each port (open, closed, or filtered).
Timeout: Set the timeout for each connection attempt based on user input.
Concurrency Settings: If parallel scanning is chosen, initialize thread or process management resources.

## Step 5: Define the Scanning Logic

For each port in the range, perform the following steps:

5.1: Open a Socket for TCP Connection
Create a TCP socket to establish a connection to the target IP on the current port.
Set the socket options to allow for non-blocking connections (useful for implementing timeouts).
5.2: Attempt to Connect to the Target Port
Attempt to connect to the target IP address on the current port:
If the connection is successful, the port is open, and you can update the status as "open."
If the connection is refused, the port is closed.
If the connection times out, the port may be filtered (e.g., by a firewall).
5.3: Handle Exceptions and Errors
Timeout: If no response is received within the defined timeout period, mark the port as "filtered."
Connection Refused: If the connection is actively refused by the target, mark the port as "closed."
Other Errors: Handle other possible network errors (e.g., unreachable host, invalid IP).

## Step 6: Store and Update Results

After scanning each port, update the status dictionary with the port number and its corresponding status (open, closed, filtered).

## Step 7: Implement Concurrency (Optional)

If the user opted for parallel scanning, create a multithreading or multiprocessing mechanism:
Assign each thread/process a subset of ports to scan.
Ensure that threads/processes operate independently but safely update the shared status dictionary.
Limit the number of concurrent threads/processes to avoid overwhelming the network or the target machine.

## Step 8: Present Scan Results

Once the scan is complete, display the results to the user in a readable format:
List all the open, closed, and filtered ports along with their port numbers.
Optionally, display the service name commonly associated with each port (e.g., HTTP for port 80, SSH for port 22) using a predefined list of known port-to-service mappings.

## Step 9: Handle Edge Cases

Invalid Hostname/IP: If the hostname cannot be resolved, return an error message and exit.
No Response from Target: If the target does not respond to any ports (e.g., offline or firewalled), notify the user that the host may be down or inaccessible.
Target Host Unreachable: Handle cases where the network is unreachable or the host is offline.
Too Many Open Ports: If too many ports are open, ensure that the program handles the output efficiently (e.g., pagination of results).

## Step 10: Provide an Option to Save Results

Allow the user to save the scan results to a file (e.g., CSV, text file) for later reference. This step can be optional based on user preferences.

## Step 11: Cleanup Resources

Close all open sockets after scanning is completed.
If multithreading was used, wait for all threads/processes to complete and clean up resources.

## Step 12: Repeat or Exit

Optionally allow the user to scan another IP address or range of ports, or exit the program.

## Additional Considerations:

Performance: For large port ranges or multiple IP addresses, implement optimizations such as:

Concurrency: Use multithreading/multiprocessing to scan multiple ports simultaneously.
Socket reuse: Avoid opening too many sockets by reusing them when possible.
Rate-limiting: Implement rate-limiting to avoid overwhelming the target system or network.
Target Discovery: Before scanning, use ping sweeps or ARP requests to check if the target is online.

UDP Scanning: UDP ports can be scanned by sending UDP packets, but detecting open ports is trickier since there's no connection handshake. Use timeouts to detect closed or filtered ports.

Firewall and IDS Detection: Be mindful that some systems may have firewalls or Intrusion Detection Systems (IDS) that block or log port scanning attempts. Implement measures to slow the scan or randomize port order to avoid detection.

Banner Grabbing (Optional): After detecting an open port, you could implement banner grabbing, which involves sending a request to the open port and reading any returned data (e.g., service version).
