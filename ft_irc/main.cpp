#include "./header/Server.hpp"

void handle_signal(int signum) {
	if (signum == SIGINT) {
		std::cout << "Received SIGINT, Shutting down server." << std::endl;
		server_running = false;
	}
}

int main(int argc, char* argv[]) {
	Server ft_irc(argv[1], argv[2]);
	server_running = true;
	struct sigaction terServer;
	terServer.sa_handler = handle_signal;
	if (sigaction(SIGINT, &terServer, 0) == -1) {
		std::cout << "SIGINT error\n";
	}
	ft_irc.runServer();
	return 0;
}
