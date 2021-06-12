#include "../deeprain/config.h"
#include "../deeprain/log.h"
#include <yaml-cpp/yaml.h>

deeprain::ConfigVar<int>::ptr g_int_value_config = 
    deeprain::Config::Lookup("system.port", (int)8080, "system port");

void test_yaml() {
    YAML::Node root = YAML::LoadFile("/home/deeprain/workspace/deeprain/bin/conf/log.yml");

    DEEPRAIN_LOG_INFO(DEEPRAIN_LOG_ROOT()) << root;
}

int main(int argc, char** argv) {
    DEEPRAIN_LOG_INFO(DEEPRAIN_LOG_ROOT()) << g_int_value_config->getValue(); 
    DEEPRAIN_LOG_INFO(DEEPRAIN_LOG_ROOT()) << g_int_value_config->toString(); 
    return 0;
}
