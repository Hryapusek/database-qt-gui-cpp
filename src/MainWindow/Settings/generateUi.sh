set -e
if ! uic settings.ui > UiSettings.hpp
then
  echo "Error while generating UiSettings.hpp"
  exit 1
fi
echo "Design hpp file generated"
