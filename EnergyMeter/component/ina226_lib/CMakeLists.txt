set(app_src ina226.c)
set(pre_req     driver      esp_driver_i2c)
idf_component_register( SRCS ${app_src}
                        INCLUDE_DIRS "."
                        REQUIRES ${pre_req} 
)