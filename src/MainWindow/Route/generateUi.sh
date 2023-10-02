set -e

if ! uic addRouteDialog.ui > UiAddRouteDialog.hpp
then
  echo "Error while generating UiAddRouteDialog.hpp"
  exit 1
fi
echo "UiAddRouteDialog.hpp file generated"

if ! uic removeRouteDialog.ui > UiRemoveRouteDialog.hpp
then
  echo "Error while generating UiRemoveRouteDialog.hpp"
  exit 1
fi
echo "UiRemoveRouteDialog.hpp file generated"