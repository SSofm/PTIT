import {
  Injectable,
  HttpException,
  HttpStatus,
  Inject,
  forwardRef,
} from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { CreateUserDto } from './dto/create-user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { User } from './entities/user.entity';
import { Repository } from 'typeorm';
import { UserCredentialDto } from './dto/UserCredentialDto';
import { CartsService } from '../carts/carts.service';

@Injectable()
export class UsersService {
  constructor(
    @InjectRepository(User)
    private readonly userRepository: Repository<User>,

    @Inject(forwardRef(() => CartsService))
    private cartsService: CartsService,
  ) {}
  async create(createUserDto: CreateUserDto) {
    const exitsUser = await this.userRepository.findOneBy({
      username: createUserDto.username,
    });
    if (exitsUser) {
      throw new HttpException('User already exists', HttpStatus.CONFLICT);
    }
    createUserDto.cart = await this.cartsService.create();
    return await this.userRepository.save(createUserDto);
  }

  async login(userCredentialDto: UserCredentialDto): Promise<{
    id: number;
    email: string;
    username: string;
    password: string;
    cartId: number;
    isAdmin: boolean;
  }> {
    const { email, password } = userCredentialDto;

    const user = await this.userRepository.findOne({ where: { email } });

    if (!user) {
      throw new HttpException('Not found user', HttpStatus.NOT_FOUND);
    }

    if (password != user.password) {
      throw new HttpException('Wrong password', HttpStatus.NOT_FOUND);
    }

    if (user && password == user.password) {
      return {
        id: user.id,
        email: user.email,
        username: user.username,
        password: user.password,
        cartId: user.cart.id,
        isAdmin: user.isAdmin,
      };
    }
  }
  create_with_out_check(createUserDto: CreateUserDto) {
    // TODO document why this method 'create_with_out_check' is empty

    return this.userRepository.save(createUserDto);
  }

  findAll() {
    return this.userRepository.find();
  }

  findOne(id: number) {
    return this.userRepository.findOneBy({ id });
  }

  update(id: number, updateUserDto: UpdateUserDto) {
    return this.userRepository.update({ id }, updateUserDto);
  }

  remove(id: number) {
    return `This action removes a #${id} user`;
  }
}
