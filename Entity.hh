#ifndef ENTITY_hh
#define ENTITY_hh

class Entity {
	private:
		
	public:
		virtual void update() = 0;
		virtual void render() = 0;
};

#endif
