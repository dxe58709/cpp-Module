#include "Serializer.hpp"

int main() {
	Data	originalData;

	originalData.id = 42;

	std::cout << "=== Before Serialization ===\n";
	std::cout << "Original Data Address: " << &originalData << "\n";
	std::cout << "Original Data ID: " << originalData.id << "\n\n";


	uintptr_t	raw = Serializer::serialize(&originalData);//ポインタのアドレスを数値に変換
	std::cout << "=== Serialized Data ===\n";
	std::cout << "Raw uintptr_t value: " << raw << "\n\n";

	Data*	deserializeData = Serializer::deserialize(raw);
	std::cout << "=== After Deserialization ===\n";
	std::cout << "Deserialized Data Address: " << deserializeData << "\n";
	std::cout << "Deserialized Data ID: " << deserializeData->id << "\n";

	return (0);
}
