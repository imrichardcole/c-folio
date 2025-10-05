typedef struct JSONDocument {
	void* foo;
} JSONDocument;

JSONDocument parse(const char* contents);

const char* get_value(JSONDocument *json, const char* key);