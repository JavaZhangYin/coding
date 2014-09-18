FILE(REMOVE_RECURSE
  "cygcommons.pdb"
  "cygcommons.dll"
  "libcommons.dll.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/commons.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
