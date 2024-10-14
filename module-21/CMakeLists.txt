set(TARGET module-21)

set(SOURCES
    main.cpp
    AirDelivery.h
    DeliveryContext.h
    ExpressDelivery.h
    GroundDelivery.h
    IDeliveryStrategy.h
)

add_executable(${TARGET} )

target_sources(${TARGET}
    PRIVATE
        ${SOURCES}
)