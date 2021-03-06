This is a daemon that listens to "xilinx_xvc" (xilinx virtual cable) traffic and 
operates JTAG over an FTDI in bitbang mode.

## Build instructions (Ubuntu)
- `sudo apt -y install libftdi-dev`
- (from xvcd dir) `make`
- If successful, there will be a program `xvcd` in the bin driectory

## Running the xvcd program

To run w/PicoEVB: enter bin dir and run `sudo ./xvcd -P 0x6015`

Note: You won't see any output if the program successfully starts. Also, it doesn't background automatically.
To have the driver run in the background run `sudo ./xvcd -P 0x6015 &`

## Getting Vivado to see the cable

To use with vivado, use the following tcl command **after the xvcd program is started**:

`open_hw; connect_hw_server; open_hw_target -xvc_url localhost:2542`

**Note**: Make sure the xvcd program is running before issuing the above command

## Program Options
| option | description |
| ------ | ----------- |
|-p (port) | set port to listen on |
|-V (vendor-id) | Attach to FTDI device with specific vendor-id |
|-P (product-id) | Attach to FTDI device with specific product-id |
|-s (connection string) | Attach to FTDI device using specially formatted string (see below) |
|-v | Enable verbose mode |

The connection string for the -s option takes precedence over -V and -P options. Here is the format for the string:

```
d:<devicenode> path of bus and device-node (e.g. "003/001") within usb device tree (usually at /proc/bus/usb/)
i:<vendor>:<product> first device with given vendor and product id, ids can be decimal, octal (preceded by "0") or hex (preceded by "0x")
i:<vendor>:<product>:<index> as above with index being the number of the device (starting with 0) if there are more than one
s:<vendor>:<product>:<serial> first device with given vendor id, product id and serial string
```


