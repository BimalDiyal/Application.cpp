
#include <iostream>

class MyHelloWorldApp : public::application {
public:
    MyHelloWorldApp(service &srv) : application(srv) {}

    void main(std::string url);
};

void MyHelloWorldApp::main(std::string /*url*/) {
    response().out() << "<h1>Hello, World!</h1>";
}

int main(int argc, char **argv) {
    try {
        cppcms::service srv(argc, argv);

        srv.applications_pool().mount(
            cppcms::applications_factory<MyHelloWorldApp>()
        );

        srv.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
