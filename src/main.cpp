#include <yaml-cpp/yaml.h>

using std::string;

int main(int argc, char** argv) {
    YAML::Node props = YAML::LoadFile("test.yaml");
    
    /* Fails in release, fine in debug */
    auto url_cs = props["datasource"]["mysql"]["url"].as<string>().c_str();
    auto user_cs = props["datasource"]["mysql"]["user"].as<string>().c_str();
    auto pw_cs = props["datasource"]["mysql"]["password"].as<string>().c_str();

    printf("url_cs: %s\n", url_cs);
    printf("user_cs: %s\n", user_cs);
    printf("pw_cs: %s\n\n", pw_cs);
    /* ------------------------------- */
    
    
    /* Fine in both release and debug */
    auto url_cs1 = props["datasource"]["mysql"]["url"].as<string>().c_str();
    printf("url_cs1: %s\n", url_cs1);
    auto user_cs1 = props["datasource"]["mysql"]["user"].as<string>().c_str();
    printf("user_cs1: %s\n", user_cs1);
    auto pw_cs1 = props["datasource"]["mysql"]["password"].as<string>().c_str();
    printf("pw_cs1: %s\n\n", pw_cs1);
    /* ------------------------------- */
    
    /* Fine in both release and debug */
    auto url = props["datasource"]["mysql"]["url"].as<string>();
    auto user = props["datasource"]["mysql"]["user"].as<string>();
    auto pw = props["datasource"]["mysql"]["password"].as<string>();

    printf("url_cs: %s\n", url.c_str());
    printf("user_cs: %s\n", user.c_str());
    printf("pw_cs: %s\n", pw.c_str());
    /* --------------------------------- */
    
    return 0;
}
