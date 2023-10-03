set -e

if ! uic addJournalRowDialog.ui > UiAddJournalRowDialog.hpp
then
  echo "Error while generating UiAddJournalRowDialog.hpp"
  exit 1
fi
echo "UiAddJournalRowDialog.hpp file generated"

if ! uic removeJournalRowDialog.ui > UiRemoveJournalRowDialog.hpp
then
  echo "Error while generating UiRemoveJournalRowDialog.hpp"
  exit 1
fi
echo "UiRemoveJournalRowDialog.hpp file generated"