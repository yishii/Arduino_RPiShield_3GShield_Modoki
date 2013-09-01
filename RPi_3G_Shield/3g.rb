require 'rubygems'
require 'net/http'
require 'uri'
require 'serialport'


def retrieve_http(uri)
  data = Net::HTTP.get URI.parse(uri)
  p data
  return data
end


serial = SerialPort.new("/dev/ttyAMA0",115200)
serial.read_timeout = 200

thread = Thread.new(serial) do
  while(1)
    data = serial.gets("\n")
    #printf("retrieved : [%s]\n",data)

    if(data =~ /HTTPGET (.*)\n/)
      printf("HTTPGET URI = [%s]\n",$1)
      serial.write retrieve_http($1)
    end
  end
end

thread.join()


