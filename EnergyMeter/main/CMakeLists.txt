idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "." "../component/ina226_lib"
                    REQUIRES    esp_driver_i2c   driver)
