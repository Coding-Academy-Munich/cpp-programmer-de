set(COMPLETED_PROJECTS
        adventure
        bmi
        builder
        catch2_intro
        cpp_patterns
        etl_examples
        fizz_buzz
        hello_world
        invoice
        library
        memory_and_polymorphism
        modern_cpp
        namespace_lookup
        pointers
        prime_factors
        raii
        range_examples
        recipes
        salaries
        shared_memory
        simple_calculator
        simple_examples
        singleton
        test_examples
        virtual_university
)

foreach (PROJECT ${COMPLETED_PROJECTS})
    if (IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${PROJECT})
        add_subdirectory(${PROJECT})
    endif ()
endforeach ()

set(OPTIONAL_COMPLETED_PROJECTS
        error_handling
)

foreach (PROJECT ${OPTIONAL_COMPLETED_PROJECTS})
    if (IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${PROJECT})
        add_subdirectory(${PROJECT} EXCLUDE_FROM_ALL)
    endif ()
endforeach ()