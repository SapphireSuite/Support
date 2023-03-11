# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Clear console.
clear

# Check current directory name.
if [ "$(basename "$(pwd)")" = "Doc" ]; then

	# Set directory to root.
	cd ..
fi

# Generate.
doxygen Doc/doxygen.config

# Open in browser
xdg-open Doc/html/index.html
