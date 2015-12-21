#!/bin/sh

openssl aes-256-cbc -k "$super_secret_password" -in traviskey.encrypted -out traviskey -d

chmod 0600 traviskey


case "${os}" in
  linux32)
	sftp -oStrictHostKeyChecking=no -i traviskey  -b - ondrej.budai@bastl1.rss.tul.cz <<EOF
put ${PWD}/SpacePilot.zip /mnt/home/ondrej.budai/builds/SpacePilot-linux32-build${TRAVIS_BUILD_NUMBER}.zip
EOF
    ;;
  linux64)
	sftp -oStrictHostKeyChecking=no -i traviskey  -b - ondrej.budai@bastl1.rss.tul.cz <<EOF
put ${PWD}/SpacePilot.zip /mnt/home/ondrej.budai/builds/SpacePilot-linux64-build${TRAVIS_BUILD_NUMBER}.zip
EOF
    ;;
  win32)
	sftp -oStrictHostKeyChecking=no -i traviskey  -b - ondrej.budai@bastl1.rss.tul.cz <<EOF
put ${PWD}/SpacePilot.zip /mnt/home/ondrej.budai/builds/SpacePilot-win32-build${TRAVIS_BUILD_NUMBER}.zip
EOF
    ;;
esac
