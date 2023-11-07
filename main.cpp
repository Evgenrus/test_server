#include <iostream>
#include "open62541pp/open62541pp.h"

int main() {
    opcua::Server server(4840);

    server.setApplicationName("test OPC UA server");

    auto obj_node = server.getObjectsNode();
    std::cout << "obj_node" << std::endl;
    auto sensors_folder = obj_node.addFolder({1, "sensors_folder"},
            "Sensors",
            opcua::ObjectAttributes{}
            .setDisplayName({"en_US", "Sensors"}));
    auto test1_sensor = sensors_folder.addObject(
            {1, "test1_sensor"},
            "test 1 sensor",
            opcua::ObjectAttributes{}
            .setDescription({"en-US", "Test 1 Sensor"}));
    auto test1_node = test1_sensor.addVariable(
        {1, "testone"},
        "Test1 variable",
        opcua::VariableAttributes{}
            .setDataType<int>()
            .setAccessLevel(UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE)
            .setDisplayName({"en-US", "test1"})
    );
    std::cout << "test1" << std::endl;
    auto test2_sensor = sensors_folder.addObject(
            {1, "test2_sensor"},
            "test 2 sensor",
            opcua::ObjectAttributes{}
                    .setDescription({"en-US", "Test 2 sensor"}));
    auto test2_node = test2_sensor.addVariable(
        {1, "testtwo"},
        "Test2 variable",
        opcua::VariableAttributes{}
            .setDataType<int>()
            .setAccessLevel(UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE)
            .setDisplayName({"en-US", "test2"})
    );
    std::cout << "test2" << std::endl;

    test1_node.writeValueScalar(42);
    test2_node.writeValueScalar(10);

    server.run();
}
