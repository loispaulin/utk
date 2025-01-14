SET(Metrics
    
    MinDist   

    TValue

    L2Discrepancy
    CenteredL2Discrepancy
    Diaphony
    GL2Discrepancy
    UnanchoredL2Discrepancy
    SymmetricL2Discrepancy
    BoundariesStarDiscrepancy

    Spectrum
    RadialSpectrum
    PCF
)

SET(pyutk_metrics)
SET(pyutk_metrics_libs pybind11::module spdlog::spdlog)

IF (OpenMP_FOUND)
    LIST(APPEND pyutk_metrics_libs OpenMP::OpenMP_CXX)
ENDIF()

FOREACH(FILE ${Metrics})
    IF(UTK_BUILD_EXE)
        add_executable(${UTK_EXE_PREFIX}${FILE} ${FILE}.cpp)
        target_include_directories(${UTK_EXE_PREFIX}${FILE} PRIVATE "${PROJECT_SOURCE_DIR}/include/")
        target_link_libraries(${UTK_EXE_PREFIX}${FILE} PRIVATE spdlog::spdlog CLI11::CLI11)
        
        IF (OpenMP_FOUND)
            target_link_libraries(${UTK_EXE_PREFIX}${FILE} PRIVATE OpenMP::OpenMP_CXX)
        ENDIF()

        IF (FFTW_FOUND)
            target_link_libraries(${UTK_EXE_PREFIX}${FILE} PRIVATE ${FFTW_LIBRARIES})
        ENDIF()

        install(TARGETS ${UTK_EXE_PREFIX}${FILE}
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
    ENDIF()
ENDFOREACH(FILE)

IF(UTK_BUILD_EXE)
    add_subdirectory(Integration)
ENDIF()

IF (UTK_PYTHON)
    # TODO : OpenMP !!!
    SET(pyutk_metrics_bindings 
        "python/Metrics.cpp"
        "python/BaseMetrics.cpp"
    )
    add_library(pyutkMetrics ${pyutk_metrics} ${pyutk_metrics_bindings})

    # Required by pybind
    set_target_properties(pyutkMetrics PROPERTIES POSITION_INDEPENDENT_CODE ON) 
    
    IF (FFTW_FOUND) 
        target_include_directories(pyutkMetrics PRIVATE ${FFTW_INCLUDE_DIRS})
        target_link_libraries(pyutkMetrics PRIVATE ${FFTW_LIBRARIES})
    ENDIF()


    target_include_directories(pyutkMetrics PRIVATE "${UTK_INCLUDE_DIR}")
    target_link_libraries(pyutkMetrics PRIVATE ${pyutk_metrics_libs})
ENDIF()