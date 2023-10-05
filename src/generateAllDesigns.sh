set -e
cd MainWindow && ./generateUi.sh
cd Auto && ./generateUi.sh && cd ..
cd Journal && ./generateUi.sh && cd ..
cd Route && ./generateUi.sh && cd ..
cd Person && ./generateUi.sh && cd ..
echo "Finished generating design files!"