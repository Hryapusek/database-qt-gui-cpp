set -e

if ! uic addAutoDialog.ui > UiAddAutoDialog.hpp
then
  echo "Error while generating UiAddAutoDialog.hpp"
  exit 1
fi
echo "UiAddAutoDialog.hpp file generated"

if ! uic removeAutoDialog.ui > UiRemoveAutoDialog.hpp
then
  echo "Error while generating UiRemoveAutoDialog.hpp"
  exit 1
fi
echo "UiRemoveAutoDialog.hpp file generated"