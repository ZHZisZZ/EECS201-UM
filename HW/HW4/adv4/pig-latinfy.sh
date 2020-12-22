
sed -E -e "s/\b([aeiouAEIOU])(\w*)/\1\2yay/g" | sed -E -e "s/\b([^ -aeiouAEIOU]+)([aeiouAEIOU])(\w*)(-|\b)/\2\3\1ay\4/g"  | sed -E -e "s/\b([a-z])([a-z]*)([A-Z])(\w*)(-|\b)/\U\1\L\2\3\4\5/g" 
