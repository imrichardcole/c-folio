typedef struct JSONKeyValuePair {
	const char* key;
	const char* value;
} JSONKeyValuePair;

typedef struct JSONDocument {
	JSONKeyValuePair* pairs;
} JSONDocument;

JSONDocument parse(const char* contents);

const char* get_value(JSONDocument *json, const char* key);