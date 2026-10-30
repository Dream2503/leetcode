/*
 * @lc app=leetcode id=2296 lang=cpp
 *
 * [2296] Design a Text Editor
 */

// @lc code=start
class TextEditor {
    std::list<char> editor;
    std::list<char>::iterator cursor;

public:
    TextEditor() : cursor(editor.end()) {}

    void addText(const std::string& text) {
        for (const char ch : text) {
            editor.insert(cursor, ch);
        }
    }

    int deleteText(const int k) {
        for (int i = 0; i < k; i++) {
            if (cursor == editor.begin()) {
                return i;
            }
            cursor = editor.erase(std::prev(cursor));
        }
        return k;
    }

    std::string cursorLeft(const int k) {
        for (int i = 0; i < k; i++) {
            if (cursor == editor.begin()) {
                break;
            }
            cursor = std::prev(cursor);
        }
        std::string res;
        auto itr = std::list<char>::reverse_iterator(cursor);

        for (int i = 0; i < 10; i++) {
            if (itr != editor.rend()) {
                res.push_back(*itr);
                itr = std::next(itr);
            } else {
                break;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string cursorRight(const int k) {
        for (int i = 0; i < k; i++) {
            if (cursor == editor.end()) {
                break;
            }
            cursor = std::next(cursor);
        }
        std::string res;
        auto itr = std::list<char>::reverse_iterator(cursor);

        for (int i = 0; i < 10; i++) {
            if (itr != editor.rend()) {
                res.push_back(*itr);
                itr = std::next(itr);
            } else {
                break;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end
