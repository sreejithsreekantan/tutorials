
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip::udp;

using namespace std;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

class tcp_connection
  : public boost::enable_shared_from_this<tcp_connection>
{
public:
  typedef boost::shared_ptr<tcp_connection> tcp_connection_ptr;

  static tcp_connection_ptr create(boost::asio::io_service& io_service)
  {
  	cout << __PRETTY_FUNCTION__ << endl;
    return tcp_connection_ptr(new tcp_connection(io_service));
  }

  tcp::socket& socket()
  {
  	cout << __PRETTY_FUNCTION__ << endl;
    return socket_;
  }

  void start()
  {
  	cout << __PRETTY_FUNCTION__ << endl;
    
    ifstream file_to_send;
    
  	file_to_send.open( "file_to_send.txt", ios_base::binary | ios_base::ate );
  	if( !file_to_send )
	{
		cout << "Failed to open file_to_send.txt " << endl;
		return;
	}

  	cout << "file_to_send.tellg() = " << file_to_send.tellg() << endl;
	boost::asio::streambuf b;
	char char_array[ 100 ];
	ostream os( &b );
	os << "file_to_send.txt" << endl;
	os << file_to_send.tellg() << endl;
	//cout << "sizeof(char_array) = " << sizeof(char_array) << endl;
	size_t size = socket_.send( b.data() );
	b.consume( size );
	file_to_send.seekg( 0, file_to_send.beg );
	
	//cout << "FILE_TO_SEND.TXT:" << endl;
	try {
	while( file_to_send.eof() == false )
	{
		file_to_send.read( char_array, 100 );
		//cout << "(gcount=" << file_to_send.gcount() << ")";
		if( file_to_send.gcount() > 0 )
		{
			//cout.write( char_array, file_to_send.gcount() );
			boost::asio::write(socket_, boost::asio::buffer( char_array, file_to_send.gcount() ) );
		}
	}
	file_to_send.close();
	cout << endl;
	}
	catch ( exception &e ) {
		cout << e.what() << endl;
	}

  }

private:
  tcp_connection(boost::asio::io_service& io_service)
    : socket_(io_service)
  {
  	cout << __PRETTY_FUNCTION__ << endl;
  }

  void handle_write()
  {
  	cout << __PRETTY_FUNCTION__ << endl;
  }

  tcp::socket socket_;
};

class tcp_server
{
public:
  tcp_server(boost::asio::io_service& io_service)
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), 143))
  {
  	cout << __PRETTY_FUNCTION__ << endl;
    start_accept();
  }

private:
  void start_accept(  )
  {
  	cout << __PRETTY_FUNCTION__ << endl;
    tcp_connection::tcp_connection_ptr new_connection =
      tcp_connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
  }

  void handle_accept(tcp_connection::tcp_connection_ptr new_connection,
      const boost::system::error_code& error)
  {
  cout << __PRETTY_FUNCTION__ << endl;
    if (!error)
    {
      new_connection->start();
      start_accept();
    }
  }

  tcp::acceptor acceptor_;
};

int main()
{
	cout << __PRETTY_FUNCTION__ << endl;
  try
  {
    boost::asio::io_service io_service;
    tcp_server file_server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
