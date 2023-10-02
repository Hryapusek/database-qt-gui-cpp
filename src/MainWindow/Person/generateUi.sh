set -e

if ! uic addPersonDialog.ui > UiAddPersonDialog.hpp
then
  echo "Error while generating UiAddPersonDialog.hpp"
  exit 1
fi
echo "UiAddPersonDialog.hpp file generated"

if ! uic removePersonDialog.ui > UiRemovePersonDialog.hpp
then
  echo "Error while generating UiRemovePersonDialog.hpp"
  exit 1
fi
echo "UiRemovePersonDialog.hpp file generated"