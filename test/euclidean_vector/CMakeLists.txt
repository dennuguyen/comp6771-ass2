cxx_test(
   TARGET test_euclidean_vector_assignments
   FILENAME "test_euclidean_vector_assignments.cpp"
   LINK euclidean_vector
)

cxx_test(
   TARGET test_euclidean_vector_constructors
   FILENAME "test_euclidean_vector_constructors.cpp"
   LINK euclidean_vector
)

cxx_test(
   TARGET test_euclidean_vector_negation
   FILENAME "test_euclidean_vector_negation.cpp"
   LINK euclidean_vector
)