FILE(REMOVE_RECURSE
  "cygsort.pdb"
  "cygsort.dll"
  "libsort.dll.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/sort.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
