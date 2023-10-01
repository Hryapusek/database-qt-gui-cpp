set -e
if ! rcc -binary resList.qrc -o resList.rcc
then
  echo "Error while generating resList.rcc"
  exit 1
fi
echo "Resource file generated"