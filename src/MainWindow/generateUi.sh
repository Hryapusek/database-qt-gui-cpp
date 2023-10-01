set -e
if ! uic mainwindow.ui > UiMainWindow.hpp
then
  echo "Error while generating UiMainWindow.hpp"
  exit 1
fi
echo "Design hpp file generated"
