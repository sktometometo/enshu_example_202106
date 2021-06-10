#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <unistd.h>

void servoWriteTo100(boost::asio::serial_port& port) {
  boost::asio::write(port, boost::asio::buffer("100"));
}

void servoWriteTo10(boost::asio::serial_port& port) {
  boost::asio::write(port, boost::asio::buffer("10"));
}

int main() {

  // 初期化
  boost::asio::io_service io;
  boost::asio::serial_port port(io, "/dev/ttyUSB0");
  port.set_option(boost::asio::serial_port_base::baud_rate(9600));

  while (true) {
    sleep(1);
    servoWriteTo10(port);
    std::cout << "hoge" << std::endl;

    sleep(1);
    servoWriteTo100(port);
    std::cout << "fuga" << std::endl;
  }
}
