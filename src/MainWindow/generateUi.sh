set -e
if ! uic mainwindow.ui > UiMainWindow.hpp
then
  echo "Error while generating UiMainWindow.hpp"
  exit 1
fi
echo "UiMainWindow.hpp file generated"
